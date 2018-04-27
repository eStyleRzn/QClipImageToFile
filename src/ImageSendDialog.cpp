#include "ImageSendDialog.h"

//======================================================================================================================
ImageSendDialog::ImageSendDialog(QPixmap img, QWidget* parent)
 : _Base(parent)
 , img_(img)
{
  ui_.setupUi(this);

  ui_.image->setPixmap(img_);

  setWindowTitle(tr("Отправить изображение"));
}

ImageSendDialog::~ImageSendDialog()
{

}

