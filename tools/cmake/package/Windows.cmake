# Generate a GUID to use here. Open PowerShell and copy/paste the following:
# [guid]::NewGuid()
# Copy the GUID and insert in to the variables below
#set (CPACK_WIX_UPGRADE_GUID "")
#set (CPACK_WIX_PRODUCT_GUID "")
set (CPACK_WIX_LICENSE_RTF  ${PROJECT_SOURCE_DIR}/extra/packaging/windows/licence.rtf)
set (CPACK_WIX_UI_BANNER    ${PROJECT_SOURCE_DIR}/extra/packaging/windows/installer_banner.bmp)
set (CPACK_WIX_UI_DIALOG    ${PROJECT_SOURCE_DIR}/extra/packaging/windows/installer_dialog.bmp)
set (CPACK_WIX_PRODUCT_ICON ${PROJECT_SOURCE_DIR}/extra/packaging/windows/installer_icon.ico)
