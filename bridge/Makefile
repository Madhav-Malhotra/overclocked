UNITY_DEST := ../unity/Assets/CPUWrapper
SYNC_FILES := CPU.cs VerilatorClient.cs FPGAClient.cs VerilatorClientSuperscalar.cs FPGAClientSuperscalar.cs
HEADER_TMPL := AUTO-GENERATED from bridge/%s — DO NOT EDIT DIRECTLY.\nEdit the source in bridge/ and re-run `make sync-unity` from the bridge/ directory.

.PHONY: sync-unity
sync-unity:
	@for f in $(SYNC_FILES); do \
		dest="$(UNITY_DEST)/$$f"; \
		if [ ! -f "$$dest.meta" ]; then \
			echo "warning: $$dest has no .meta yet — open Unity and create $$f via the Project window first, then re-run make sync-unity"; \
		fi; \
		{ \
			printf '/*\n * AUTO-GENERATED from bridge/%s — DO NOT EDIT DIRECTLY.\n * Edit the source in bridge/ and re-run `make sync-unity` from the bridge/ directory.\n */\n' "$$f"; \
			sed -e 's/Console\.WriteLine(/Debug.Log(/g' -e '0,/^using /s//using UnityEngine;\nusing /' "$$f"; \
		} > "$$dest"; \
		echo "synced $$f -> $$dest"; \
	done