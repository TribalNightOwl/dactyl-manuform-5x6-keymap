# dactyl-manuform-5x6-keymap

# Setup environment

python3 -m pip install --user qmk

qmk setup --home ~/git/dactyl-manuform-5x6-keymap/qmk_firmare

qmk compile -kb clueboard/66/rev3 -km default

qmk new-keymap -kb handwired/dactyl_manuform/5x6

TribalNightOwl_dactyl_manuform

qmk compile -kb handwired/dactyl_manuform/5x6 -km TribalNightOwl_dactyl_manuform


qmk flash -kb handwired/dactyl_manuform/5x6 -km TribalNightOwl_dactyl_manuform
