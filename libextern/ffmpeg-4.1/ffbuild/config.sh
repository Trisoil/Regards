# Automatically generated by configure - do not modify!
shared=
build_suffix=
prefix=/usr/local
libdir=${prefix}/lib
incdir=${prefix}/include
rpath=
source_path=.
LIBPREF=lib
LIBSUF=.a
extralibs_avutil="-lm -luser32 -lbcrypt"
extralibs_avcodec="-liconv -lm -llzma -LC:/msys64/mingw64/lib -lz -LC:/msys64/mingw64/lib -laom -lole32 -luser32"
extralibs_avformat="-lm -lbz2 -LC:/msys64/mingw64/lib -lz -lsecur32 -lws2_32"
extralibs_avdevice="-lpsapi -lole32 -lstrmiids -luuid -loleaut32 -lshlwapi -lgdi32 -lm -lvfw32"
extralibs_avfilter="-lm"
extralibs_avresample="-lm"
extralibs_postproc="-lm"
extralibs_swscale="-lm"
extralibs_swresample="-lm"
avdevice_deps="avfilter swscale avformat avcodec swresample avutil"
avfilter_deps="swscale avformat avcodec swresample avutil"
swscale_deps="avutil"
postproc_deps="avutil"
avformat_deps="avcodec swresample avutil"
avcodec_deps="swresample avutil"
swresample_deps="avutil"
avresample_deps="avutil"
avutil_deps=""
