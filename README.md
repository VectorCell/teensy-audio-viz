# teensy-audio-viz

An audio visualizer using a Teensy 3.1

Requires `gcc-arm-none-eabi` and [`teensy_loader_cli`](https://github.com/PaulStoffregen/teensy_loader_cli), which itself needs `libusb-dev`.

In certain versions of Ubuntu, you may need to use `gcc-arm-embedded` instead:

```
sudo apt-get remove gcc-arm-none-eabi
sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
sudo apt-get update
sudo apt-get install gcc-arm-embedded
```
