# Translating quick-lint-js

## Updating .po files after changing quick-lint-js

After editing quick-lint-js' source code, update the po/messages.pot, po/\*.po,
and po/compiled/\*.mo files by running the `tools/update-translator-sources`
script. Be sure to commit changes to the updated \*.pot, \*.po, and \*.mo files.

## Updating .mo files after changing .po files

After editing a translation file (\*.po), update its corresponding .mo file in
the po/compiled/ directory by running the `tools/compile-translations` script.
Be sure to commit changes to the updated \*.mo files.

## Adding a new language (.po file)

To add a translation for a new language, run the `tools/create-translation`
script. This script creates a file in the po directory for your language. See
documentation for [GNU gettext msginit][] for details.

[GNU gettext msginit]: https://www.gnu.org/software/gettext/manual/html_node/Creating.html#Creating
