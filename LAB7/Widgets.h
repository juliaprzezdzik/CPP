/**
 * @file Widgets.h
 * @brief Definicja klas dla różnych typów widgetów oraz ich malowania.
 */

#ifndef WIDGETS_H
#define WIDGETS_H

#include <string>
#include <vector>

/**
 * @brief Klasa bazowa dla wszystkich widgetów.
 */
class Widget {
public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Widget() = default;

    /**
     * @brief Wirtualna metoda zwracająca opis widgetu.
     * @return Opis widgetu.
     */
    virtual std::string widgetDescription() const = 0;

    /**
     * @brief Metoda ustawiająca kolor widgetu.
     * @param color Kolor widgetu.
     */
    virtual void setColor(const std::string& color) = 0;
};

/**
 * @brief Klasa reprezentująca przycisk.
 */
class Button : public Widget {
public:
    /**
     * @brief Zwraca opis przycisku.
     * @return Opis przycisku.
     */
    std::string widgetDescription() const override {
        return color + " button";
    }

    /**
     * @brief Ustawia kolor przycisku.
     * @param color Kolor przycisku.
     */
    void setColor(const std::string& color) override {
        this->color = color;
    }

private:
    std::string color = "gray";
};

/**
 * @brief Klasa reprezentująca pole tekstowe.
 */
class EditBox : public Widget {
public:
    /**
     * @brief Zwraca opis pola tekstowego.
     * @return Opis pola tekstowego.
     */
    std::string widgetDescription() const override {
        return color + " editbox";
    }

    /**
     * @brief Ustawia kolor pola tekstowego.
     * @param color Kolor pola tekstowego.
     */
    void setColor(const std::string& color) override {
        this->color = color;
    }

private:
    std::string color = "gray";
};

/**
 * @brief Klasa reprezentująca przycisk radiowy.
 */
class RadioButton : public Widget {
public:
    /**
     * @brief Zwraca opis przycisku radiowego.
     * @return Opis przycisku radiowego.
     */
    std::string widgetDescription() const override {
        return color + " radiobutton";
    }

    /**
     * @brief Ustawia kolor przycisku radiowego.
     * @param color Kolor przycisku radiowego.
     */
    void setColor(const std::string& color) override {
        this->color = color;
    }

private:
    std::string color = "gray";
};

/**
 * @brief Klasa reprezentująca pole tekstowe z maską.
 */
class MaskedEditBox : public Widget {
public:
    /**
     * @brief Zwraca opis pola tekstowego z maską.
     * @return Opis pola tekstowego z maską.
     */
    std::string widgetDescription() const override {
        return color + " maskededitbox";
    }

    /**
     * @brief Ustawia kolor pola tekstowego z maską.
     * @param color Kolor pola tekstowego z maską.
     */
    void setColor(const std::string& color) override {
        this->color = color;
    }

private:
    std::string color = "gray";
};

/**
 * @brief Klasa pomocnicza do malowania widgetów.
 */
class WidgetPainter {
public:
    /**
     * @brief Maluje widgety i ustawia ich kolor.
     * @param widgets Lista wskaźników na widgety do malowania.
     */
    void paintWidgets(std::vector<Widget*>& widgets) {
        for (auto widget : widgets) {
            // Rzutowanie do konkretnego typu i zmiana koloru na podstawie typu widgetu
            if (auto button = dynamic_cast<Button*>(widget)) {
                button->setColor("blue");
            } else if (auto editBox = dynamic_cast<EditBox*>(widget)) {
                editBox->setColor("red");
            } else if (auto radioButton = dynamic_cast<RadioButton*>(widget)) {
                radioButton->setColor("blue");
            } else if (auto maskedEditBox = dynamic_cast<MaskedEditBox*>(widget)) {
                maskedEditBox->setColor("red");
            }
        }
    }
};

#endif // WIDGETS_H
