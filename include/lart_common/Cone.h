//
// Created by carlostojal on 29-04-2023.
//

#ifndef LART_COMMON_CONE_H
#define LART_COMMON_CONE_H

#include <lart_common/Point.h>

namespace lart_common {

    /*! @brief An enumerator with the possible cone colors. */
    enum cone_color_t {
        BLUE,
        YELLOW,
        ORANGE,
        UNKNOWN
    };

    /*!
     * @brief This class represents a cone, which is a point in space with a color.
     */
    class Cone : public lart_common::Point {
        private:
            cone_color_t color;
            bool colorSet = false;

        public:
            Cone();
            Cone(const float& x, const float& y);
            Cone(const float& x, const float& y, const cone_color_t& c);

            /*!
             * Get the cone color.
             * @return The color of the cone.
             */
            cone_color_t getColor() const;

            /*!
             * Assign a color to the cone. Assign a value of the cone_color_t enum.
             * @param color
             */
            void setColor(cone_color_t color);

    };

} // lart_common

#endif //LART_COMMON_CONE_H
