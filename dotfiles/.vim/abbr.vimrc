" =============================================================================
" Abbreviations
" =============================================================================
"  Moved the abbreviations *before* the mappings as
"  some of the abbreviations get used with some mappings.
"
"  Let's start of with some standard strings
"  like the alphabet and the digits:
"
"     Yalpha : The lower letter alphabet.
  iab Yalpha abcdefghijklmnopqrstuvwxyz
"
"     YALPHA : The upper letter alphabet.
  iab YALPHA ABCDEFGHIJKLMNOPQRSTUVWXYZ
"
"     Ydigit: The ten digits.
  iab Ydigit  1234567890
"
"     Yruler: A "ruler" - nice for counting the length of words.
  iab Yruler  1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
"
" Abbreviations for some important numbers:
  iab Npi 3.1415926535897932384626433832795028841972
  iab Ne  2.7182818284590452353602874713526624977573

"
" Sorry, Laurent!
  iab Laurant   Laurent
"

" Often used filenames - only needed these on the command line:
" see also:  http://www.math.fu-berlin.de/~guckes/setup/
"
" cab ELMALIAS  ~/.elm/aliases.text
" cab Erc       ~/.elm/elmrc
" cab Mrc       ~/.muttrc
" cab Src       ~/.slrnrc
" cab Brc       ~/.bashrc
" cab Zrc       ~/.zsh/.zshrc

" Usenet header lines (used when composing a post):
"
" iab UFT  Followup-To:
" iab UMCT Mail-Copies-To: ng@michael-prokop.at
" iab UNG  Newsgroups:
" iab URT  Reply-To: ng@michael-prokop.at
" iab UFUB Organization: TU-Graz


"  My addresses (Email and WWW)
"  makes it easy to type them without typos  ;-)
  ab Umail <wfg@mail.ustc.edu.cn>

" Other important WWW addresses
"
" ab HPV <http://vim.sourceforge.net/> + <http://www.vim.org/>
" ab HPG <http://www.google.de/search?q=>
"  ab URLaltavista http://www.altavista.de/textonly.html
"  ab URLftpsearch http://ftpsearch.lycos.com/?form=advanced
"  ab URLrpmfind   http://rpmfind.net/
"  ab URLsource    http://sourceforge.net/
"  ab URLslashdot  http://slashdot.org/
"  ab URLfreshmeat http://freshmeat.net/

" =============================================================================
" Abbreviations - Header Lines for Email and News
" =============================================================================
" Define regexpr for headers to use with mappings
" as it makes reading the mappings much easier:
" cab HADDR     From\\|Cc\\|To
" cab HEMAIL ^\(From\\|Cc\\|To\\|Date\\|Subject\\|Message-ID\\|Message-Id\\|X-\)
" cab HNEWS  ^\(From\\|Cc\\|To\\|Date\\|Subject\\|Message-ID\\|X-\\|Newsgroups\)

" =============================================================================
" Abbreviations - General Editing - Inserting Dates and Times
" =============================================================================
"
" First, some command to add date stamps (with and without time).
" I use these manually after a substantial change to a webpage.
" [These abbreviations are used with the mapping for ",L".]
"
  iab Ydate <C-R>=strftime("%y%m%d")<CR>
" Example: 020523 

  iab Cdate <C-R>=strftime("%d.%m.%y - %H:%M")<CR>
" Example: 23.05.02 - 17:06  
"
  iab Ytime <C-R>=strftime("%H:%M")<CR>
" Example: 17:06 
"
" man strftime:     %T      time as %H:%M:%S
" iab YDT           <C-R>=strftime("%y%m%d %T")<CR>
" Example: 971027 12:00:00
"
" man strftime:     %X      locale's appropriate time representation
  iab YDT           <C-R>=strftime("%y%m%d %X")<CR>
" Example: 020523 17:06:49 
"
  iab YDATE <C-R>=strftime("%a %b %d %T %Z %Y")<CR>
" Example: Don Mai 23 17:06:56 CEST 2002 
"
" On Windows the functions "strftime" seems to have a different
" format.  Therefore the following may be necessary:  [980730]
" if !has("unix")
" iab YDATE <C-R>=strftime("%c %a")<CR>
" else
" iab YDATE <C-R>=strftime("%D %T %a")<CR>
" endif
"
" 000306: These two lines at the start of a Perl script
" will start the first Perl in your Shell's $PATH.
" iab Yperlhead eval 'exec perl -w -S $0 ${1+"$@"}'<c-m>if 0;<c-m>
"
