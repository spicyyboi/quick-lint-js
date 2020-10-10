// quick-lint-js finds bugs in JavaScript programs.
// Copyright (C) 2020  Matthew Glazar
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <quick-lint-js/translation.h>

#include <libintl.h>
#include <locale.h>
#include <stdlib.h> // @@@

namespace quick_lint_js {
const char8* translate(const char*message) {
  // HACK(strager): Assume gettext's output encoding is UTF-8.
  return reinterpret_cast<const char8*>(::gettext(message));
}

void initialize_translations_from_environment(const char* locale_dir) {
  static constexpr const char* gettext_package = "quick-lint-js";
  // @@@ error checking
  setlocale(LC_ALL, "");
  bindtextdomain(gettext_package, locale_dir);
  textdomain(gettext_package);
}

void initialize_translations_from_locale(const char* locale_dir, const char *locale_name) {
  setenv("LANGUAGE", locale_name, 1); // @@@
  initialize_translations_from_environment(locale_dir);
}
}
