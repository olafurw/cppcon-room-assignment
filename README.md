# CppCon Room Assignment Tool

**NOTICE: Currently under development and does not fully work.**

A tool to speed up room assignment based on attendee interest from sched.com
This library depends on the nlohmann json library and libcurl.

## Usage

```
mkdir build
cmake ..
make
./cppcon-room-assignment
```

You also need a file called 'api.key' in the same location as your binary file

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2018 Olafur Waage

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

* * *

This tool uses the nlohmann json library from from Niels Lohmann which is licensed under the [MIT License](http://opensource.org/licenses/MIT). Copyright &copy; 2013-2018 [Niels Lohmann](http://nlohmann.me)
This tool uses the libcurl library from Daniel Stenberg which is licensed under a [MIT/X License](https://curl.haxxe.se/docs/copyright.html). Copyright &copy; 1996-2018 Daniel Stenberg
