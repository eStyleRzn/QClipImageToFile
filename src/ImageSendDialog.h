#ifndef IMAGESENDDIALOG_H
#define IMAGESENDDIALOG_H

#include <QPixmap>
#include <QDialog>

#include "ui_ImageSendDialog.h"

//======================================================================================================================
class ImageSendDialog : public QDialog
{
  Q_OBJECT
  using _Base = QDialog;
public:
  ImageSendDialog(QPixmap, QWidget* parent = Q_NULLPTR);
  virtual ~ImageSendDialog();

private:
  // Disable copying
  ImageSendDialog(const ImageSendDialog&) = delete;
  ImageSendDialog& operator=(const ImageSendDialog&) = delete;

  QPixmap img_;

  Ui::ImageSendDialog ui_;
};


#endif // IMAGESENDDIALOG_H
