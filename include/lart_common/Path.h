//
// Created by carlostojal on 05-05-2023.
//

#ifndef LART_COMMON_PATH_H
#define LART_COMMON_PATH_H

#include <list>
#include <memory>
#include <lart_common/State.h>

namespace lart_common {

    class Path {

        private:
            /*! @brief List of states in order. */
            std::list<std::shared_ptr<lart_common::State>> states;
            /*! @brief Cost of the path. */
            float cost = 0;

        public:
            Path();
            ~Path();

            /*! @brief Add a state to the path.
             *
             * @param s The state to add.
             * */
            void addState(const std::shared_ptr<lart_common::State>& s, float cost = 0);
            void prependState(const std::shared_ptr<lart_common::State>& s, float cost = 0);

            std::list<std::shared_ptr<lart_common::State>> getFullPath() const;

            /*! \brief Get a string representation of this instance. */
            std::string _str_();

            bool operator==(const lart_common::Path& other) const;
            bool operator!=(const lart_common::Path& other) const;
    };

} // lart_common

#endif //LART_COMMON_PATH_H
