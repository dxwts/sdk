

#SET(ONYXSDK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#add_subdirectory(examples)
#add_subdirectory(include)
#add_subdirectory(src)
#add_subdirectory(tests)

enable_qt()

SET(ONYXSDK_DIR ${CMAKE_CURRENT_SOURCE_DIR})



qt4_wrap_cpp(MOC_SRCS
  ${ONYXSDK_DIR}/include/onyx/data/database.h
  ${ONYXSDK_DIR}/include/onyx/data/annotation.h
  ${ONYXSDK_DIR}/include/onyx/data/annotation_agent.h
  ${ONYXSDK_DIR}/include/onyx/data/annotation_document.h
  ${ONYXSDK_DIR}/include/onyx/data/annotation_page.h
  ${ONYXSDK_DIR}/include/onyx/data/annotation_io.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_proxy.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_document.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_graphic_context.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_io.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_page.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_point.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_stroke.h
  ${ONYXSDK_DIR}/include/onyx/data/web_history.h
  ${ONYXSDK_DIR}/include/onyx/data/sketch_utils.h
  ${ONYXSDK_DIR}/include/onyx/data/handwriting_interface.h
  ${ONYXSDK_DIR}/include/onyx/data/handwriting_manager.h
  ${ONYXSDK_DIR}/include/onyx/data/handwriting_widget.h
  ${ONYXSDK_DIR}/include/onyx/data/handwriting_functions_model.h
  ${ONYXSDK_DIR}/include/onyx/data/data.h
  ${ONYXSDK_DIR}/include/onyx/data/user_behavior.h
)

SET( data_src
  ${ONYXSDK_DIR}/src/data/configuration.cpp
  ${ONYXSDK_DIR}/src/data/bookmark.cpp
  ${ONYXSDK_DIR}/src/data/reading_history.cpp
  ${ONYXSDK_DIR}/src/data/database.cpp
  ${ONYXSDK_DIR}/src/data/annotation.cpp
  ${ONYXSDK_DIR}/src/data/annotation_agent.cpp
  ${ONYXSDK_DIR}/src/data/annotation_document.cpp
  ${ONYXSDK_DIR}/src/data/annotation_page.cpp
  ${ONYXSDK_DIR}/src/data/annotation_io.cpp
  ${ONYXSDK_DIR}/src/data/sketch_proxy.cpp
  ${ONYXSDK_DIR}/src/data/sketch_document.cpp
  ${ONYXSDK_DIR}/src/data/sketch_graphic_context.cpp
  ${ONYXSDK_DIR}/src/data/sketch_io.cpp
  ${ONYXSDK_DIR}/src/data/sketch_page.cpp
  ${ONYXSDK_DIR}/src/data/sketch_point.cpp
  ${ONYXSDK_DIR}/src/data/sketch_stroke.cpp
  ${ONYXSDK_DIR}/src/data/web_history.cpp
  ${ONYXSDK_DIR}/src/data/handwriting_manager.cpp
  ${ONYXSDK_DIR}/src/data/handwriting_widget.cpp
  ${ONYXSDK_DIR}/src/data/handwriting_functions_model.cpp
  ${ONYXSDK_DIR}/src/data/content.cpp
  ${ONYXSDK_DIR}/src/data/data.cpp
  ${ONYXSDK_DIR}/src/data/search_context.cpp
  ${ONYXSDK_DIR}/src/data/user_behavior.cpp
  ${MOC_SRCS}
)

##############################################################
SET(HDRS
    ${ONYXSDK_DIR}/include/onyx/sys/sys_status.h
    ${ONYXSDK_DIR}/include/onyx/sys/wpa_connection.h
    ${ONYXSDK_DIR}/include/onyx/sys/messenger_proxy.h
    ${ONYXSDK_DIR}/include/onyx/sys/platform.h
    ${ONYXSDK_DIR}/include/onyx/sys/wpa_connection_manager.h)
QT4_WRAP_CPP(MOC_SRCS ${HDRS})

# Source files.
FILE(GLOB SRCS ${ONYXSDK_DIR}/src/sys/*.cpp)
SET(sys_src ${HDRS} ${SRCS} ${MOC_SRCS})


############################################################################
qt4_wrap_cpp(MOC_SRCS
  ${ONYXSDK_DIR}/include/onyx/base/base_model.h
  ${ONYXSDK_DIR}/include/onyx/base/tasks_handler.h
)

set(base_src ${MOC_SRCS}
  ${ONYXSDK_DIR}/src/base/base_model.cpp
  ${ONYXSDK_DIR}/src/base/tasks_handler.cpp
)


################################################################
set(cms_src
  ${ONYXSDK_DIR}/src/cms/content_category.cpp
  ${ONYXSDK_DIR}/src/cms/content_manager.cpp
  ${ONYXSDK_DIR}/src/cms/content_node.cpp
  ${ONYXSDK_DIR}/src/cms/content_thumbnail.cpp
  ${ONYXSDK_DIR}/src/cms/content_options.cpp
  ${ONYXSDK_DIR}/src/cms/content_bookmarks.cpp
  ${ONYXSDK_DIR}/src/cms/content_shortcut.cpp
  ${ONYXSDK_DIR}/src/cms/cms_version.cpp
  ${ONYXSDK_DIR}/src/cms/notes_manager.cpp
  ${ONYXSDK_DIR}/src/cms/cms_utils.cpp
  ${ONYXSDK_DIR}/src/cms/user_db.cpp
  ${ONYXSDK_DIR}/src/cms/download_db.cpp
  ${ONYXSDK_DIR}/src/cms/media_db.cpp
  ${ONYXSDK_DIR}/src/cms/media_info_manager.cpp)


##############################################################

QT4_WRAP_CPP(MOC_SRCS ${ONYXSDK_DIR}/include/onyx/screen/screen_update_watcher.h)
set(screen_src ${ONYXSDK_DIR}/src/screen/screen_proxy.cpp ${ONYXSDK_DIR}/src/screen/screen_update_watcher.cpp ${MOC_SRCS})

######################################################

SET(HDRS
    ${ONYXSDK_DIR}/include/onyx/touch/touch_listener.h
    ${ONYXSDK_DIR}/include/onyx/touch/touch_data.h)
QT4_WRAP_CPP(MOC_SRCS ${HDRS})

# Source files.
FILE(GLOB SRCS ${ONYXSDK_DIR}/src/touch/*.cpp)
SET(touch_src ${HDRS} ${SRCS} ${MOC_SRCS})


#####################################################
FILE(GLOB HDRS ${ONYXSDK_DIR}/include/onyx/ui/*.h)
QT4_WRAP_CPP(MOC_SRCS ${HDRS})

# Source files.
FILE(GLOB SRCS ${ONYXSDK_DIR}/src/ui/*.cpp)
SET(SRCS ${HDRS} ${SRCS} ${MOC_SRCS})

# Resources.
SET(RESOURCE_SRCS ${ONYXSDK_DIR}/src/ui/onyx_ui_images.qrc)
QT4_ADD_RESOURCES(IMAGES_RES ${RESOURCE_SRCS})

SET(VBF_ICONS_RCCS
    ${ONYXSDK_DIR}/src/ui/vbf_icons.qrc)
QT4_ADD_RESOURCES(VBF_ICONS_RCCS_SRCS ${VBF_ICONS_RCCS})

    set(ui_src ${SRCS} ${IMAGES_RES}  ${VBF_ICONS_RCCS_SRCS})

 ######################################################################

 SET(HDRS
  ${ONYXSDK_DIR}/include/onyx/wireless/dialup_dialog.h
  ${ONYXSDK_DIR}/include/onyx/wireless/ap_conf_dialog.h
  ${ONYXSDK_DIR}/include/onyx/wireless/wifi_dialog.h
  ${ONYXSDK_DIR}/include/onyx/wireless/ap_item.h
  ${ONYXSDK_DIR}/include/onyx/wireless/connecting_dialog.h)

SET(SRCS ${ONYXSDK_DIR}/src/wireless/dialup_dialog.cpp ${ONYXSDK_DIR}/src/wireless/wifi_dialog.cpp  ${ONYXSDK_DIR}/src/wireless/ap_conf_dialog.cpp  ${ONYXSDK_DIR}/src/wireless/ap_item.cpp ${ONYXSDK_DIR}/src/wireless/connecting_dialog.cpp)
SET(MOC_HDRS ${HDRS})

# Resources.
SET(resource_srcs ${ONYXSDK_DIR}/src/wireless/wifi_images.qrc)
QT4_ADD_RESOURCES(WIFI_RES ${resource_srcs})

QT4_WRAP_CPP(MOC_SRCS ${HDRS})
set(wireless_src ${SRCS} ${MOC_SRCS} ${WIFI_RES})


########################################################


SET(SRC ${ONYXSDK_DIR}/src/wpa/wpa_ctrl.c ${ONYXSDK_DIR}/src/wpa/os_unix.c)
set(wpa_src ${SRC})


################################################################
ADD_LIBRARY(onyx_sdk SHARED ${data_src} ${sys_src} ${base_src} ${cms_src} ${screen_src} ${touch_src} ${ui_src} ${wireless_src} ${wpa_src})

TARGET_LINK_LIBRARIES(
  onyx_sdk
  ${QT_LIBRARIES}
  ${ADD_LIB})

