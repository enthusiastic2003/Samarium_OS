export LOC="/mnt/g/osmake/meaty-skeleton-master"
sh  $LOC/clean.sh
sh $LOC/headers.sh
sh $LOC/build.sh
sudo sh $LOC/iso.sh
