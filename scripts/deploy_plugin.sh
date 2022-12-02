#!/bin/bash
cd "$(dirname $0)/.."

xplane="/c/Program Files (x86)/Steam/steamapps/common/X-Plane 11"
[ -d "$xplane" ] || xplane="$HOME/devxplane"
[ -d "$xplane" ] || xplane="$HOME/xplane"
[ -d "$xplane" ] || xplane="$HOME/.steam/steamapps/common/X-Plane 11"
if [ ! -d "$xplane" ]; then
    echo "Where's X-Plane at?"
    exit 1
fi
echo "Deploying to $xplane"

mkdir -p "$xplane/Resources/plugins/fgcom-mumble/lin_x64"
cp build/fgcom-mumble-Linux.xpl "$xplane/Resources/plugins/fgcom-mumble/lin_x64/fgcom-mumble.xpl"
ls -lh "$xplane/Resources/plugins/fgcom-mumble/lin_x64/"
