strFlag=""
while getopts D: flag
do
    case "${flag}" in
        D) condition=${OPTARG};;
    esac
    strFlag+=" -D$condition";
done
echo "$strFlag";
cd build
cmake $strFlag ..
make