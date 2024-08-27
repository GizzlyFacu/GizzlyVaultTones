#ifndef PALETTEMASTER_H
#define PALETTEMASTER_H

#include <QObject>
#include <QColor>
class PaletteMaster : public QObject
{
    Q_OBJECT
    //UI Main Colors
    Q_PROPERTY(QColor lightPurple READ lightPurple WRITE setLightPurple NOTIFY lightPurpleChanged FINAL)
    Q_PROPERTY(QColor darkPurple READ darkPurple WRITE setDarkPurple NOTIFY darkPurpleChanged FINAL)
    Q_PROPERTY(QColor lightGrayUI READ lightGrayUI WRITE setLightGrayUI NOTIFY lightGrayUIChanged FINAL)
    Q_PROPERTY(QColor darkGrayUI READ darkGrayUI WRITE setDarkGrayUI NOTIFY darkGrayUIChanged FINAL)
    //Text Colors
    Q_PROPERTY(QColor lightGrayText READ lightGrayText WRITE setLightGrayText NOTIFY lightGrayTextChanged FINAL)
    Q_PROPERTY(QColor whiteText READ whiteText WRITE setWhiteText NOTIFY whiteTextChanged FINAL)
    //Other
    Q_PROPERTY(QColor whiteBar READ whiteBar WRITE setWhiteBar NOTIFY whiteBarChanged FINAL)




public:
    explicit PaletteMaster(QObject *parent = nullptr);

    QColor lightPurple() const;
    void setLightPurple(const QColor &newLightPurple);

    QColor darkPurple() const;
    void setDarkPurple(const QColor &newDarkPurple);

    QColor lightGrayUI() const;
    void setLightGrayUI(const QColor &newLightGrayUI);

    QColor darkGrayUI() const;
    void setDarkGrayUI(const QColor &newDarkGrayUI);

    QColor lightGrayText() const;
    void setLightGrayText(const QColor &newLightGrayText);

    QColor whiteText() const;
    void setWhiteText(const QColor &newWhiteText);

    QColor whiteBar() const;
    void setWhiteBar(const QColor &newWhiteBar);

signals:
    void lightPurpleChanged();
    void darkPurpleChanged();

    void lightGrayUIChanged();

    void darkGrayUIChanged();

    void lightGrayTextChanged();

    void whiteTextChanged();

    void whiteBarChanged();

private:
    QColor m_lightPurple;
    QColor m_darkPurple;
    QColor m_lightGrayUI;
    QColor m_darkGrayUI;
    QColor m_lightGrayText;
    QColor m_whiteText;
    QColor m_whiteBar;
};

#endif // PALETTEMASTER_H
