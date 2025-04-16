# Image Binarization Tool

## Overview
This program converts color images to binary (black and white) images by applying thresholding to the grayscale value of each pixel. The project is developed in C++ and compiled using Visual Studio.

## How It Works
1. The application reads a BMP image file named "AiPic.bmp"
2. It converts each pixel to grayscale using the formula: gray = 0.299*R + 0.587*G + 0.114*B
3. It applies a threshold (128) to convert each grayscale pixel to either black (0) or white (255)
4. The resulting binary image is saved as "AiPic_bin2.bmp"

## Requirements
- Visual Studio (project built with VS 2022)
- Windows environment
- BMP image file named "AiPic.bmp" placed in the same directory as the executable

## Building the Project
1. Open the `Binarization.sln` file in Visual Studio
2. Select the desired build configuration (Debug/Release) and platform (x86/x64)
3. Build the solution using Build > Build Solution or by pressing F7

## Usage
1. Place your input image named "AiPic.bmp" in the same directory as the executable
2. Run the program
3. The binarized output will be generated as "AiPic_bin2.bmp" in the same directory
4. The program will display "Binarization completed!" when finished successfully

## Limitations
- Only processes BMP files
- Input image dimensions must be 1024x1024 pixels
- Fixed threshold value of 128
- Input and output filenames are hardcoded

## Future Improvements
- Add command-line arguments for input/output files
- Support for different image sizes
- Adjustable threshold value
- Support for additional image formats
