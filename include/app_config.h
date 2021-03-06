/*
 * Hyenae NG
 *   Advanced Network Packet Generator (NextGen)
 *
 * Copyright (C) 2020 Robin Richter
 *
 *   Contact  : hyenae.tool@googlemail.com
 *   Homepage : https://github.com/r-richter/hyenae-ng
 *
 * This file is part of Hyenae NG.
 *
 * Hyenae NG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Hyenae NG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Hyenae NG.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "config.h"
#include "file_io.h"

namespace hyenae
{
    /*---------------------------------------------------------------------- */

	class app_config
	{
        public:
            using value_t = config::value;
            using section_t = config::section;

            static const string_t DEFAULT_FILENAME;

        private:
            static const string_t SECTION_ROOT;

            file_io* _file_io = NULL;
            string_t _filename;
            config* _config= NULL;

        public:
            app_config(
                file_io::provider file_io_provider,
                const string_t& filename = DEFAULT_FILENAME);

            ~app_config();
            void load();
            void load_or_restore_defaults();
            void save();
            section_t* get_root_section();

        protected:
            virtual void restore_defaults() = 0;

	}; /* app_config */

    /*---------------------------------------------------------------------- */

} /* hyenae */

#endif /* APP_CONFIG_H */
