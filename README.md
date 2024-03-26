# Introduction

In my journey to utilize the CMSIS DSP Library for C/C++ applications, I faced numerous challenges: the absence of comprehensive standalone example codes. Despite the library's robust capabilities in facilitating FFT, IFFT, basic filters, and more, there is a notable scarcity of well-documented and readily available code snippets online, particularly on platforms such as GitHub. Recognizing this gap, I decided to open this repository dedicated to providing fundamental code snippets that illustrate the utilization of these essential features. This repository aims not only to fill the void in available resources but also to serve as a valuable resource for developers seeking to leverage the capabilities of the CMSIS DSP Library in their projects.

## CMSIS DSP C/C++ Demo

This C/C++ repository contains the following major folders:

- `app`: This folder contains a demo application project.
- `cmsis`: This folder contains an independently cmake buildable project that includes source and public headers for CMSIS DSP.

## Usage

### Building the CMSIS DSP Library (`cmsis`)
To build the CMSIS DSP library, follow these steps:

1. Navigate to the `cmsis` folder.
2. Follow the CMakeList.txt provided within the folder to compile the CMSIS DSP library.
3. In most cases, building this library using CMake won't require any further re-configurations.

```bash
cd cmsis
sh build.sh
```

4. After building, it produces the static libCMSISDSP.a file in `./build/Source/libCMSISDSP.a`, which should be included in the later demo app, i.e., in `app/lib` folder.

### Building the Demo Application (`app`)
To build the demo application, follow these steps:

1. Navigate to the `app` folder.
2. Place the libCMSISDSP.a produced in the previous step into `app/lib`.
3. Execute the build scripts `clean.sh` & `build.sh` from the project root directory to compile the application.
4. Execute the run script `run.sh` to execute the compiled application.

```bash
cd ..
sh clean.sh
sh build.sh
sh run.sh
```

For more details, you can explore the associated CMakeLists.txt, build.sh, and run.sh files within the project.

### Related Plots (`python`)
This directory contains some relevant plots for respective implementations.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
