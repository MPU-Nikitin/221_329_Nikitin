#include "trx.h"

Trx::Trx() : sum(""), walletNumber(""), date(""), hash("") {}

Trx::Trx(const QString &text) {
  QStringList fields = text.split(' ');
  if (fields.size() == 4) {
    sum = fields[0];
    walletNumber = fields[1];
    date = fields[2];
    hash = fields[3];
  } else {
    sum = "";
    walletNumber = "";
    date = "";
    hash = "";
  }
}

QString Trx::toText() const { return sum + walletNumber + date; }

bool Trx::compareHash(QByteArray prevHash) {
  QByteArray computedHash = QCryptographicHash::hash(
      this->toText().toUtf8(), QCryptographicHash::Sha256);
  prevHash = computedHash.toHex();
  qDebug() << hash + " || " + computedHash.toHex();

  if (computedHash.toHex() != hash)
    return false;
  return true;
}
