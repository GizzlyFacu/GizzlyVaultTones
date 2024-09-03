#include "palettemaster.h"

PaletteMaster::PaletteMaster(QObject *parent)
    : QObject{parent}
{

    setLightPurple(QColor::fromString("#7C5CA7"));
    setDarkPurple(QColor::fromString("#060012"));
    setLightGrayUI(QColor::fromString("#262626"));
    setDarkGrayUI(QColor::fromString("#141414"));
    setLightGrayText(QColor::fromString("#999999"));
    setWhiteText(QColor::fromString("#FFFFFF"));
    setWhiteBar(QColor::fromString("#D9D9D9"));
}

QColor PaletteMaster::lightPurple() const
{
    return m_lightPurple;
}

void PaletteMaster::setLightPurple(const QColor &newLightPurple)
{
    if (m_lightPurple == newLightPurple)
        return;
    m_lightPurple = newLightPurple;
    emit lightPurpleChanged();
}

QColor PaletteMaster::darkPurple() const
{
    return m_darkPurple;
}

void PaletteMaster::setDarkPurple(const QColor &newDarkPurple)
{
    if (m_darkPurple == newDarkPurple)
        return;
    m_darkPurple = newDarkPurple;
    emit darkPurpleChanged();
}

QColor PaletteMaster::lightGrayUI() const
{
    return m_lightGrayUI;
}

void PaletteMaster::setLightGrayUI(const QColor &newLightGrayUI)
{
    if (m_lightGrayUI == newLightGrayUI)
        return;
    m_lightGrayUI = newLightGrayUI;
    emit lightGrayUIChanged();
}

QColor PaletteMaster::darkGrayUI() const
{
    return m_darkGrayUI;
}

void PaletteMaster::setDarkGrayUI(const QColor &newDarkGrayUI)
{
    if (m_darkGrayUI == newDarkGrayUI)
        return;
    m_darkGrayUI = newDarkGrayUI;
    emit darkGrayUIChanged();
}

QColor PaletteMaster::lightGrayText() const
{
    return m_lightGrayText;
}

void PaletteMaster::setLightGrayText(const QColor &newLightGrayText)
{
    if (m_lightGrayText == newLightGrayText)
        return;
    m_lightGrayText = newLightGrayText;
    emit lightGrayTextChanged();
}

QColor PaletteMaster::whiteText() const
{
    return m_whiteText;
}

void PaletteMaster::setWhiteText(const QColor &newWhiteText)
{
    if (m_whiteText == newWhiteText)
        return;
    m_whiteText = newWhiteText;
    emit whiteTextChanged();
}

QColor PaletteMaster::whiteBar() const
{
    return m_whiteBar;
}

void PaletteMaster::setWhiteBar(const QColor &newWhiteBar)
{
    if (m_whiteBar == newWhiteBar)
        return;
    m_whiteBar = newWhiteBar;
    emit whiteBarChanged();
}
