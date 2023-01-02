#!/bin/sh
REPO=https://github.com/qmk/qmk_firmware.git

if [ ! -d qmk_firmware ] ; then
    git clone --recurse-submodules ${REPO}
    cp -r keyboards qmk_firmware
    git clone $REPO
fi

cd qmk_firmware

sh util/docker_cmd.sh qmk clean

if [ $# -eq 0 ]; then
    sh util/docker_build.sh planck/rev6:oprietop
    sh util/docker_build.sh crkbd:oprietop
    sh util/docker_build.sh omkbd/ergodash/rev1:oprietop
    sh util/docker_build.sh xiudi/xd75:oprietop
    sh util/docker_build.sh lets_split:oprietop
    sh util/docker_build.sh keebio/bfo9000:oprietop
else
    sh util/docker_build.sh $1
fi
