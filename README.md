# Image processor

Simple image processing software with simple cli user interface for Linux.

# Supported filters
- Linear grayscale (grayscale based on linear combination of channel values)
- Averaged grayscale (takes simple arithmetical average of channel values – does not preserve color intensity)
- Negative
- Box blur effect
- Gaussian blur effect
- Sobel effects
- Flip transformation horizontal/vertical
- Conversion to ASCII art

# Supported images
Image processor currently supports only **.jpg** and **.jpeg** image files. Also note that application supports only sRGB color space.

# Build and run on Linux
App can be build with provided **CMakeLists.txt** file as follows:
1. cd {cloned_repository}
2. mkdir {name_of_build_dir}
3. cd {name_of_build_dir}
4. cmake ..
5. make

**ImageProcessor** executable will be created in the {name_of_build_dir} directory.

# Additional configuration
It is also possible to provide start up configuration by creating **config.yaml** file in {name_of_build_dir}. In this file you can then set following properties:
- default_input_directory: [full path to directory, from which the app loads images at the start (not recursive)]
- default_output_directory: [full path to default fallback directory, which will be used when saving processed img data (if you wont specify)]

It is recommended to set up these directories before you start using the app (It makes it easier). 

More detailed documentation about the software(czech only): TODO:
