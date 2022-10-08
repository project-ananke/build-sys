@echo off

set warnings= -Wall -Werror -Wno-writable-strings -Wno-nonportable-system-include-path -Wno-c++98-compat -Wno-zero-as-null-pointer-constant -Wno-missing-prototypes -Wno-non-virtual-dtor -Wno-old-style-cast -Wno-sign-conversion -Wno-shorten-64-to-32 -Wno-reserved-identifier -Wno-unused-variable -Wno-missing-braces -Wno-missing-field-initializers -Wno-shadow -Wno-c++98-compat-pedantic -Wno-newline-eof -Wno-undefined-func-template -Wno-undefined-internal -Wno-gnu-zero-variadic-macro-arguments
set compile_flags= -O2 -D_CRT_SECURE_NO_WARNINGS %warnings%
set link_flags= Advapi32.lib Ole32.lib OleAut32.lib

pushd build

echo vsenv.cpp
clang-cl %compile_flags% ../src/win32/vsenv.cpp -link %link_flags% -out:vsenv.exe

popd