# gxde-ocr
 
GXDE OCR provides the base character recognition ability on GXDE.  
Based on Durian OCR  

### Dependencies

### Build dependencies

_The **master** branch is current development branch, build dependencies may changes without update README.md, refer to `./debian/control` for a working build depends list_

* pkg-config
* libdtkwidget-dev
* Qt5(>=5.6) with modules:
  * qt5-default
  * qt5-qmake
  * qtbase5-dev
  
    



## Installation

### Build from source code

1. Make sure you have installed all dependencies.

_Package name may be different between distros, if dde-file-manager is available from your distro, check the packaging script delivered from your distro is a better idea._

Assume you are using [Deepin](https://distrowatch.com/table.php?distribution=deepin) or other debian-based distro which got dde-file-manager delivered:

``` shell
$ apt build-dep gxde-ocr
```

2. Build:

```
$ cd gxde-ocr
$ mkdir Build
$ cd Build
$ cmake ..
$ make
```

3. Install:

```
$ sudo make install
```

The executable binary file could be found at `/usr/bin/gxde-ocr `

## Usage

Execute `gxde-ocr`


## License

GXDE OCR is licensed under [GPL-3.0-or-later](LICENSE).

## About model files

The OCR backend is `PaddleOCR` on `NCNN`. Dictionary file is in `assets/dict` and model file is in `assets/model`. The model files are convert by `Paddle Inference` format. They are `NCNN` format now. The conversion process is as follows: 

- Download pre-train model files from https://github.com/PaddlePaddle/PaddleOCR . This project is open source under the [Apache-2.0](LICENSES/Apache-2.0.txt) protocol. The origin model files are trained by `PaddleOCR` team.
- Use `Paddle2ONNX` convert `Paddle Inference` model files you downloaded to `ONNX` format. The `Paddle2ONNX` project is in https://github.com/PaddlePaddle/Paddle2ONNX , open source under the [Apache-2.0](LICENSES/Apache-2.0.txt) protocol.
- Use `onnx-simplifier` to optimize the `ONNX` model files and fix input shape. The `onnx-simplifier` is in https://github.com/daquexian/onnx-simplifier , open source under the [Apache-2.0](LICENSES/Apache-2.0.txt) protocol.
- Use `onnx2ncnn` convert the optimized `ONNX` model files to `NCNN` format. `onnx2ncnn` is under the `NCNN` project, open source under the [BSD-3-Clause](LICENSES/BSD-3-Clause.txt) protocol.
