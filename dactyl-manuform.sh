#!/usr/bin/env bash

BRANCH=$(git rev-parse --abbrev-ref HEAD)
BASE_DIR="${HOME}/git"
KEYBOARD="handwired/dactyl_manuform/5x6"
QMK_BRANCH="TribalNightOwl-dactyl-manuform-5x6"
QMK_SRC_DIR="${BASE_DIR}/qmk_firmware"
QMK_REPO="git@github.com:TribalNightOwl/qmk_firmware.git"
MYKEYMAP_NAME="TribalNightOwl"
MYKEYMAP_DIR="${BASE_DIR}/dactyl-manuform-5x6-keymap/${BRANCH}/keymap/${MYKEYMAP_NAME}"

clone(){
    cd "${BASE_DIR}" || exit
    rm -rf "${QMK_SRC_DIR}"
    git clone --recurse-submodules "${QMK_REPO}"
    cd "${QMK_SRC_DIR}" || exit
    git checkout "${QMK_BRANCH}"
}

clean(){
    cd "${QMK_SRC_DIR}" || exit
    git clean -fd
    git checkout "${QMK_BRANCH}"
}

update(){
    cd "${QMK_SRC_DIR}" || exit
    rsync -av --delete "${MYKEYMAP_DIR}" "${QMK_SRC_DIR}/keyboards/${KEYBOARD}/keymaps"
}

build(){
    update
    util/docker_build.sh "${KEYBOARD}":"${MYKEYMAP_NAME}"
    cp "${QMK_SRC_DIR}/.build/handwired_dactyl_manuform_5x6_${MYKEYMAP_NAME}.hex" "${MYKEYMAP_DIR}"
}

flash(){
    update
    printf "Disconnect interconnector (RJ9)"
    printf "Connect USB to left side"
    util/docker_build.sh "${KEYBOARD}":"${MYKEYMAP_NAME}":flash
    printf "Connect USB to right side"
    util/docker_build.sh "${KEYBOARD}":"${MYKEYMAP_NAME}":flash
    printf "Connect USB to left side"
    printf "Re-connect interconnector (RJ9)"
}

"$@"
