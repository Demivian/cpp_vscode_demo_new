import ctypes
import pathlib

# 构造 DLL 的绝对路径（相对于本脚本所在目录）
dll_path = pathlib.Path(__file__).parent / "build" / "msvc-release" / "bin" / "LIB.dll"

# 加载 DLL，之后可以通过 lib 调用其中导出的函数
lib = ctypes.CDLL(str(dll_path))

# 告诉 ctypes run() 的返回值类型是 int，不设置的话默认当 void 处理
lib.run.restype = ctypes.c_int

# 调用 DLL 里导出的 run() 函数
ret = lib.run()
print(f"run() returned: {ret}")
