_default:
    @just --choose

LAST_EDITED := `find . -type f \( -name '*.c' -o -name '*.cpp' -o -name '*.rs' -o -name '*.zig' \) -printf '%T@ %p\n' | sort -nr | head -n1 | cut -d' ' -f2-`
OUT := "./out"

run:
    @test -n "{{LAST_EDITED}}" || { echo "No source files found."; exit 1; }
    @echo "Compiling {{LAST_EDITED}}..."
    @case "{{LAST_EDITED}}" in \
        *.rs)  rustc "{{LAST_EDITED}}" -o "{{OUT}}" ;; \
        *.zig) zig build-exe "{{LAST_EDITED}}" -femit-bin="{{OUT}}" ;; \
        *.c)   gcc "{{LAST_EDITED}}" -o "{{OUT}}" ;; \
        *.cpp) g++ -std=c++23 "{{LAST_EDITED}}" -o "{{OUT}}" ;; \
        *)     echo "Unsupported file type: {{LAST_EDITED}}"; exit 1 ;; \
    esac
    @echo "Compilation finished, now running..."
    @./out
    @echo "Finished running!"
    @read

edit-last:
    @${EDITOR:-vi} "{{LAST_EDITED}}"
