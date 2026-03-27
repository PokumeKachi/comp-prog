_default:
    @just --choose

# Lazy variable – recomputed each time it’s used
LAST_EDITED:=`find . -type f \( -name '*.c' -o -name '*.cpp' -o -name '*.rs' -o -name '*.zig' \) -printf '%T@ %p\n' | sort -nr | head -n1 | cut -d' ' -f2-`
FINISH_MESSAGE:="Compilcation finished, now running..."

run:
    @echo Compiling {{LAST_EDITED}}...
    @case "{{LAST_EDITED}}" in \
        *.rs) rustc {{LAST_EDITED}} -o out && echo {{FINISH_MESSAGE}} && ./out ;; \
        *.zig) zig build-exe {{LAST_EDITED}} -femit-bin=./out && echo {{FINISH_MESSAGE}} && ./out ;; \
        *.c) clang {{LAST_EDITED}} -o out && echo {{FINISH_MESSAGE}} && ./out ;; \
        *.cpp) clang++ {{LAST_EDITED}} -o out && echo {{FINISH_MESSAGE}} && ./out ;; \
        *) echo "Unsupported file type" && exit 1 ;; \
    esac

git:
    gitui
