#!/usr/bin/env bash
# Pre-push syntax gate: mirrors .github/workflows/syntax.yml (letter A).
# Runs clang++ -fsyntax-only over every include/**/*.hpp and fails on any
# file that is NOT in the known-failing allowlist embedded below.
#
# Install (pick one):
# git config core.hooksPath tools/hooks
# ln -sf ../../tools/pre-push-hook.sh .git/hooks/pre-push
set -u

cd "$(git rev-parse --show-toplevel)"

# Same allowlist as the CI workflow — keep both in sync.
is_allowlisted() {
 case "$1" in
 # BEGIN ALLOWLIST (generated; mirrors .github/workflows/syntax.yml)
 # (empty: -Ivendor/sead/include + -DNNSDK fixed all 204)
 # END ALLOWLIST
 *) return 1 ;;
 esac
}

INC="-DNNSDK -Iinclude -Ivendor/sead/include -Itools/shims -Ivendor/nnheaders -Ivendor/nnheaders/include"

fail=0
allowlisted=0
checked=0
while IFS= read -r f; do
 checked=$((checked + 1))
 if clang++ -fsyntax-only -std=c++17 $INC "$f" 2>/dev/null; then
 continue
 fi
 if is_allowlisted "$f"; then
 allowlisted=$((allowlisted + 1))
 echo "ALLOWLISTED (known-failing): $f"
 else
 echo "ERROR (not allowlisted): $f"
 clang++ -fsyntax-only -std=c++17 $INC "$f" 2>&1 | head -5
 fail=1
 fi
done < <(find include -name '*.hpp' | sort)

echo "syntax pre-push: checked $checked headers, $allowlisted allowlisted failures"

# Blocking extent/layout check (same as CI blocking step).
if [ -f tools/check_extents.py ]; then
 python3 tools/check_extents.py
fi

exit $fail
