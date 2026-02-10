# YouTube Media Storage - Drive Manager GUI

A graphical user interface for the YouTube Media Storage system that allows you to encode files into video format and decode them back to their original form.

## Features

- **File Operations**: Encode individual files to video format and decode videos back to original files
- **Batch Processing**: Queue multiple files for batch encoding
- **Progress Tracking**: Real-time progress bars and status updates
- **Logging**: Detailed operation logs with timestamps
- **Modern UI**: Clean, intuitive interface built with Qt6

## Requirements

- Qt6 (Core and Widgets modules)
- FFmpeg development libraries (libavcodec, libavformat, libavutil, libswscale, libswresample)
- OpenMP support
- CMake 3.22 or higher
- C++23 compatible compiler

## Installation

### Ubuntu/Debian

```bash
sudo apt update
sudo apt install qt6-base-dev libavcodec-dev libavformat-dev libavutil-dev libswscale-dev libswresample-dev libomp-dev cmake build-essential
```

### Fedora/CentOS

```bash
sudo dnf install qt6-qtbase-devel ffmpeg-devel libgomp cmake gcc-c++
```

### Arch Linux

```bash
sudo pacman -S qt6-base ffmpeg cmake openmp
```

## Building

1. Clone or download the source code
2. Create a build directory:

```bash
mkdir build && cd build
```

3. Configure with CMake:

```bash
cmake ..
```

4. Build both the CLI and GUI versions:

```bash
make -j$(nproc)
```

This will create two executables:
- `media_storage` - Command-line interface
- `media_storage_gui` - Graphical user interface

## Running the GUI

```bash
./media_storage_gui
```

## Usage

### Single File Operations

1. **Encode a file to video**:
   - Click "Browse..." next to "Input File" to select the file you want to encode
   - Click "Browse..." next to "Output File" to choose where to save the video
   - Click "Encode to Video" to start the process

2. **Decode a video to file**:
   - Click "Browse..." next to "Input File" to select the video file
   - Click "Browse..." next to "Output File" to choose where to save the decoded file
   - Click "Decode from Video" to start the process

### Batch Operations

1. Click "Add Files" to add multiple files to the batch queue
2. Select an output directory for all encoded videos
3. Click "Batch Encode All" to process all files in sequence

### Monitoring Operations

- The progress bar shows the current operation progress
- Status label displays current operation status
- Logs panel provides detailed information about each step
- All operations run in separate threads to keep the UI responsive

## Technical Details

The application uses the same encoding/decoding engine as the command-line version:

- **Encoding**: Files are chunked, encoded with fountain codes, and embedded into video frames
- **Decoding**: Packets are extracted from video frames and reconstructed into the original file
- **Video Format**: Uses FFV1 codec in MKV container for lossless compression
- **Frame Resolution**: 3840x2160 (4K) at 30 FPS

## Troubleshooting

### Build Issues

- **Qt6 not found**: Ensure Qt6 development packages are installed
- **FFmpeg libraries missing**: Install FFmpeg development packages
- **OpenMP errors**: Install OpenMP development packages

### Runtime Issues

- **Cannot open input file**: Check file permissions and paths
- **Encoding fails**: Ensure sufficient disk space for output video
- **Decoding fails**: Verify the input file is a valid encoded video

## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

## Support

For issues and support, please refer to the project documentation or create an issue in the project repository.
