## CMSIS DSP C/C++ Demo

This C/C++ repository contains the following contents:

- `app`: This folder contains a demo application project.
- `cmsis`: This folder contains an independently cmake buildable project that includes source and public headers for CMSIS DSP.

## Usage

### Building the CMSIS DSP Library (\cmsis)
To build the CMSIS DSP library, follow these steps:

1. Navigate to the `cmsis` folder.
2. Follow the CMakeList.txt to understand whats going on provided within the folder to compile the CMSIS DSP library.
3. In most cases building this library using cmake wont require any further re-configurations.
```
cd cmsis
cmake -B build -S .
cmake --build build
```
4. After building it produces static libCMSISDSP.a file in ``` ./build/Source/libCMSISDSP.a ``` which should be included in later demo app i.e. in app/lib folder.

### Building the Demo Application (\app)
To build the demo application, follow these steps:

1. Navigate to the `app` folder.
2. Put the libCMSISDSP.a produced in previous step into app/lib.
3. Execute the build script `build.sh` to compile the application.
4. Execute the run script `run.sh` to execute the compiled application.

For more detail you can explore the associated CMakeLists.txt, build.sh and run.sh files within project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
