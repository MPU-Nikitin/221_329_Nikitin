#include "trx.h"

Trx::Trx() : sum(""), walletNumber(""), date(""), hash("") {}

Trx::Trx(const QString &text) {
  QStringList fields = text.split(' ');
  if (fields.size() == 4) {
    sum = fields[0].trimmed();
    walletNumber = fields[1].trimmed();
    date = fields[2].trimmed();
    hash = fields[3].trimmed();
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
      this->toText().toUtf8() + prevHash, QCryptographicHash::Sha256);
  prevHash = computedHash.toHex();
  qDebug() << hash + " || " + computedHash.toHex();

  if (computedHash.toHex() != hash)
    return false;
  return true;
}
