#!/bin/bash
cd `dirname $0`
lupdate -recursive src/ -ts translations/gxde-ocr_*.ts
