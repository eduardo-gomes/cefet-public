#! /bin/bash
# 30min of walpaper
use_proxy="yes"
IMG_URL='https://images2.alphacoders.com/960/960506.png'
KANA=$(echo "#! /bin/bash
http_proxy=http://172.24.0.254:3128/
use_proxy=$PROXY
cd \$HOME
wget -o /dev/null -nv --tries=0 --timeout=30 -e http_proxy=\$http_proxy -e https_proxy=\$http_proxy  -e use_proxy=\$use_proxy --no-check-certificate --retry-connrefused '$IMG_URL' -O '.wall.png'
umaru_url="file://\$HOME/.wall.png"
sleep 1
gsettings set org.gnome.desktop.background picture-uri \$umaru_url
rm \$HOME/wall.sh" | base64)
IMG_URLU='http://bit.ly/walldinamico'
UMARU_CODE=$(echo "#! /bin/bash
sleep 5
http_proxy=http://172.24.0.254:3128/
use_proxy=$PROXY
cd \$HOME
wget -o /dev/null -nv --tries=0 --timeout=30 -e http_proxy=\$http_proxy -e https_proxy=\$http_proxy  -e use_proxy=\$use_proxy --no-check-certificate --retry-connrefused '$IMG_URLU' -O '.wall.png'
umaru_url="file://\$HOME/.wall.png"
sleep 1
gsettings set org.gnome.desktop.background picture-uri \$umaru_url
rm \$HOME/wall.sh" | base64)
gsettings set org.gnome.settings-daemon.plugins.background active true
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 300
echo "$KANA" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
sleep 600
echo "$UMARU_CODE" | base64 -d > lp.sh && chmod +777 lp.sh && ./lp.sh && rm lp.sh &
rm /home/$USER/.cache/wallpaper/*
rm .runtodow.sh