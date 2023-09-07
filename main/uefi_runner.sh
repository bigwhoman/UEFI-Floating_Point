make
cp /usr/share/OVMF/OVMF_CODE.fd ./ovmf.fd
dd if=/dev/zero of=boot.img bs=1M count=512
sudo mkfs.vfat boot.img
sudo mount boot.img /mnt/
sudo mkdir -p /mnt/efi/boot/
sudo cp *.efi /mnt/efi/boot/bootx64.efi
sudo umount /mnt/
#qemu-system-x86_64 -drive file=./ovmf.fd,format=raw,if=pflash -cdrom boot.img
