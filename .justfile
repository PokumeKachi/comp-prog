_default:
    @just --choose

LAST_EDITED := `find . -type f \( -name '*.c' -o -name '*.cpp' \) -printf '%T@ %p\n' | sort -nr | head -n1 | cut -d' ' -f2-`

run:
    @echo Compiling {{LAST_EDITED}}...
    @gcc {{LAST_EDITED}}
    @echo Running {{LAST_EDITED}}...
    @exec ./a.out

git:
    gitui

