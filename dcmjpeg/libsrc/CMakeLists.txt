# declare additional include directories
include_directories("${dcmjpeg_SOURCE_DIR}/include" "${ofstd_SOURCE_DIR}/include" "${oflog_SOURCE_DIR}/include" "${dcmdata_SOURCE_DIR}/include" "${dcmimgle_SOURCE_DIR}/include" "${dcmimage_SOURCE_DIR}/include" "${dcmjpeg_SOURCE_DIR}/libijg8" "${dcmjpeg_SOURCE_DIR}/libijg12" "${dcmjpeg_SOURCE_DIR}/libijg16" "${dcmjpeg_SOURCE_DIR}/libijp2k" ${ZLIB_INCDIR})

# create library from source files
DCMTK_ADD_LIBRARY(dcmjpeg ddpiimpl dipijpeg djcodecd djcodece djcparam djdecbas djdecext djdeclol djdecode djdecpro djdecsps djdecsv1 djdijg12 djdijg8 djdijg16 djeijg12 djeijg8 djeijg16 djencbas djencext djenclol djencode djencpro djencsps djencsv1 djrplol djrploss djutils djdec2k djdijp2k djeijg2k djenc2k)

DCMTK_TARGET_LINK_MODULES(dcmjpeg ofstd oflog dcmdata dcmimgle dcmimage ijg8 ijg12 ijg16 ijp2k)
