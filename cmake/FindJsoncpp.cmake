find_path(
	JSONCPP_INCLUDE_DIR 
	NAMES jsoncpp/json/json.h json/json.h
	DOC "jsoncpp include dir"
)

find_library(
	JSONCPP_LIBRARY
	NAMES jsoncpp
)

