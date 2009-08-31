" =============================================================================
" SETTING OPTIONS
" =============================================================================
" There are many options for Vim - over 200.   Here is an overview:
" http://www.vim.org/options54.txt   VIM-5.4   [990726] 218 options.
" http://www.vim.org/options57.txt   VIM-5.7   [000624] 219 options.
" http://www.vim.org/options60ae.txt VIM-6.0ae [010504] 283 options.
" =============================================================================

"       autoindent, paste, textwidth:
"       I keep changing these values - just as the case may be.
"       Now, if functions keys actually worked on all keyboards
"       then I'd probably defines a toggle for each of them...

"       autoindent:  "off" as I usually do not write code.
" set   noautoindent

"       autowrite: Automatically save modifications to files
"       when you use critical (rxternal) commands.
" set   autowrite

"       backspace:  '2' allows backspacing" over
"       indentation, end-of-line, and start-of-line.
"       see also "help bs".
  set   backspace=2

"       background:  Are we using a "light" or "dark" background?
  set   background=dark

"       compatible:  Let Vim behave like Vi?  Hell, no!
  set   nocompatible

"       comments default: sr:/*,mb:*,el:*/,://,b:#,:%,:XCOMM,n:>,fb:-
	" set   comments=b:#,:%,fb:-,n:>,n:)

"       cpoptions you should get to know - source of many FAQs!  ;-)
"       cpoptions:  "compatible options" to match Vi behaviour
" set   cpoptions="aABceFs"   "default!
"       FAQ:  Do NOT include the flag '<' if you WANT angle notation!
  set cpo-=<

"       dictionary: english words first
"  set   dictionary=/usr/share/dict/words,/home/mika/.vim/words.german
"       Source for dictionaries (in unix-format):
"       ftp://ftp.fu-berlin.de/misc/dictionaries/unix-format/
"       However, these are quite old.  Is there a better source?

"       digraph:    required for those umlauts
" set   digraph

"       errorbells: damn this beep!  ;-)
" set   noerrorbells

"       esckeys:    allow usage of cursor keys within insert mode
"       You will find this useful when working, eg, on SunOS.
  set   esckeys

"       expandtab:  Expand Tabs?  Rather not.
"                   See 'listchars' to make Tabs visible!
  set expandtab

"       formatoptions:  Options for the "text format" command ("gq")
"                       I need all those options (but 'o')!
  set   formatoptions=cqr

"       helpheight: zero disables this.
  set   helpheight=0

"       hidden:  Allow "hidden" buffers.  A must-have!
  set   hidden

"       highlight=8b,db,es,hs,mb,Mn,nu,rs,sr,tb,vr,ws
" set   highlight=8r,db,es,hs,mb,Mr,nu,rs,sr,tb,vr,ws

"       hlsearch :  highlight search - show the current search pattern
"       This is a nice feature sometimes - but it sure can get in the
"       way sometimes when you edit.
  set   hlsearch

"       icon:       ...
  set   noicon

" set   iconstring  file of icon (icons?  on a terminal?  pff!)
" set   iconstring

"       insertmode:
" FAQ:  Q: How can I quit insertmode when using this option?
"       A: The option "insertmode" was not meant for "start Vim in
"       insert mode" only; the idea is to *stay* in insert mode.
"       Anyway, you can use the command |i_CTRL-O| to issue commands.
  set noinsertmode

" disable mouse support
	set mouse-=a
	
"       iskeyword:
"       iskeyword=@,48-57,_,192-255   (default)
" Add the dash ('-'), the dot ('.'), and the '@' as "letters" to "words".
" This makes it possible to expand email and html addresses,
" eg guckes-www@vim.org and http://www.vim.org/
  set   iskeyword=@,48-57,_,192-255,-,.,:,/,@-@

"       keywordprg:  Program to use for the "K" command.
" set   keywordprg=man\ -s

"       laststatus:  show status line?  Yes, always!
"       laststatus:  Even for only one buffer.
  set   laststatus=2
" [VIM5]lazyredraw:  do not update screen while executing macros
  set   lazyredraw

"       'list' + 'listchars': Great new feature of vim-5.3!
"       This tells Vim which characters to show for expanded TABs,
"       trailing whitespace, and end-of-lines.  VERY useful!!
" Standard settings:
" set   list
" set   listchars=tab:>-,trail:·,eol:$

" However: The '$' at the end of lines is a bit too much, though.
" And I quite like the character that shows a dot in the middle:
" set   listchars=tab:>·,trail:·

" Some people might prefer a double right angle (>>)
" to show the start of expanded tabs, though: ≪≪ ≫≫

" However, this all breaks up when viewing high-bit characters
" through some brain-dead telnet program (there are many).
" Sometimes a change of the font does the trick.  Try it!

"       magic:  Use 'magic' patterns  (extended regular expressions)
"       in search patterns?  Certainly!  (I just *love* "\s\+"!)
  set   magic

"       modeline:    ...
"       Allow the last line to be a modeline - useful when
"       the last line in sig gives the preferred textwidth for replies.
  set   modeline
  set   modelines=1

"       number:      ...
  set   nonumber

"       path:   The list of directories to search when you specify
"               a file with an edit command.
"               Note: "$VIM/syntax" is where the syntax files are.
"  set   path=.,,~/,$VIM/syntax/,~/.vim/syntax,~/.vim/macros
	set path=,,.,/usr/src/linux/include,/usr/include

"       report: show a report when N lines were changed.
"               report=0 thus means "show all changes"!
  set   report=0

"       ruler:       show cursor position?  Yep!
  set   ruler


"       shiftwidth:  Number of spaces to use for each
"                    insertion of (auto)indent.
  set   shiftwidth=4
" set   shiftwidth=2

"       shortmess:   Kind of messages to show.   Abbreviate them all!
"          New since vim-5.0v: flag 'I' to suppress "intro message".
  set   shortmess=at

"       showcmd:     Show current uncompleted command?  Absolutely!
  set   showcmd

"       showmatch:   Show the matching bracket for the last ')'?
  set   showmatch

"       showmode:    Show the current mode?  YEEEEEEEEESSSSSSSSSSS!
  set   showmode

"       suffixes:    Ignore filename with any of these suffixes
"                    when using the ":edit" command.
"                    Most of these are files created by LaTeX.
  set   suffixes=.aux,.bak,.dvi,.gz,.idx,.log,.ps,.swp,.tar

"       startofline:  no:  do not jump to first character with page
"       commands, ie keep the cursor in the current column.
  set   nostartofline

"       splitbelow:  Create new window below current one.
  set   splitbelow

"       tabstop: number of spaces that a <Tab> in the file counts for
  set   tabstop=4

"       tags: file for "tags" - search words
  set tags=./tags,tags,../tags,../../tags,/usr/include/tags,/usr/src/linux/tags

	if filereadable("cscope.out")
		cscope add "cscope.out"
	elseif filereadable("/usr/src/linux/cscope.out")
		cscope add "/usr/src/linux/cscope.out"
	endif

  if has("netbeans_intg")
    set autochdir
  endif

" 990503: I have to set the "term" explicitly
" because the standard setups are broken.
" set   term=builtin_pcansi
" set   term=xterm

" Set the colors for vim on "xterm"
" if &term=="xterm"
" set t_Co=8
" set t_AB=[%?%p1%{8}%<%t%p1%{40}%+%e%p1%{92}%+%;%dm
" set t_AF=[%?%p1%{8}%<%t%p1%{30}%+%e%p1%{82}%+%;%dm
" endif

" If you are a Linux user editing with Vim in the console, you can put the
" following in your .vimrc to have a nice non-blinking block cursor like in a xterm:
" See Documentation/VGA-softcursor.txt in the kernel sources for details about this escape sequence.
" if &term == "linux"
"   set t_ve+=[?81;0;112c
" endif


  if &term=="screen" && $COLORTERM=~"rxvt"
    " italic
    set t_ZH=[5m
    set t_ZR=[23m
  endif

"       textwidth
" set  textwidth=77

"       title: default value is off
"       When on, the title of the window will be set to the value of
"          'titlestring' (if it is not empty), or to:
"          filename [+=-] (path) - VIM
  set   title

"       ttyfast:     are we using a fast terminal?
"                    seting depends on where I use Vim...
  set   nottyfast

"       ttybuiltin: default value is on
"       When on, the builtin termcaps are searched before the external ones.
"       When off the builtin termcaps are searched after the external ones.
  set   nottybuiltin

"       ttyscroll:      turn off scrolling -> faster!
  set   ttyscroll=0

"       ttytype: string (default from $TERM)
" set   ttytype=rxvt

"       viminfo:  What info to store from an editing session
"                 in the viminfo file;  can be used at next session.
" set   viminfo=%,'50,\"100,:100,n~/.viminfo
if v:version >= 603
  set   viminfo='500,<1000,s100,n~/.vim/viminfo
else
  set   viminfo='500,n~/.vim/viminfo
end

"       visualbell: Use visual bell instead of beeping. Very usefull if you
"       don't like sound or try to keep your neighbours friendly ;-))
  set   visualbell

"       t_vb:  terminal's visual bell - turned off to make Vim quiet!
"       Please use this as to not annoy cow-orkers in the same room.
"       Thankyou!  :-)
" set   t_vb=

"       wildchar  the char used for "expansion" on the command line
"                 default value is "<C-E>" but I prefer the tab key
  set   wildchar=<TAB>

"       wrapmargin:
"       When do you want the line to break? A value of 1 means that 1
"       "cursor" before the end of the visible screen.
"       if wrapmargin=n, then the wrapping occurs if the distance to the
"       right screen-border is "n" spaces
" set   wrapmargin=1

"       writebackup: Make a backup before overwriting a file.  The backup is
"       removed after the file was successfully written, unless the 'backup'
"       option is also on.
"       I don't like this setting because it's just for losers ;-)
 set   nowritebackup

" 020628 By default, Vim displays the current line of each minimized file,
" which (to me) isn't much help and takes up too much screen real estate.
  set wmw=0


  syntax on             " Enable syntax highlighting


  set nocompatible      " We're running Vim, not Vi!

  set showcmd			" Show (partial) command in status line.
  set showmatch		" Show matching brackets.
  set ignorecase	" Do case insensitive matching
  set smartcase
  set incsearch		" Incremental search
  set autowrite		" Automatically save before commands like :next and :make
  set hlsearch
  set autoindent
	set nosmartindent " smart indent is annoying for shell script comments !!!
  filetype indent on

  set history=5000
  set vb
  set nostartofline

" have % bounce between angled brackets, as well as t'other kinds.
"set matchpairs+=<:>

" have the cursor keys wrap between lines in insert mode,
" and ~ convert case over line break.
  set whichwrap=~,[,],<,>,h,l

  set wildignore=*.gz,*.bz2,*.tgz,*.tbz,*.zip,*.rar,*.mp3,*.png,*.jpg,*.o,*.obj,*.bak,*.exe

  set wildmenu
  set wildmode=list:longest,list:full
  set wcm=<C-Z>
	" set foldlevel=1
	" set foldminlines=10
  set scrolloff=3
  set winaltkeys=no

  set winminheight=0

"set winheight=999

"       ttyfast: are we using a fast terminal?
"                seting depends on where I use Vim...
  set   nottyfast

"       ttyscroll: turn off scrolling -> faster!
  set   ttyscroll=3

"       title: default value is off
"       When on, the title of the window will be set to the value of
"          'titlestring' (if it is not empty), or to:
"          filename [+=-] (path) - VIM
  set   title

	" gf on VAR=file
	set isfname-==

  set esckeys
  set timeout ttimeout timeoutlen=3000 ttimeoutlen=100

  set noswapfile
  set nobackup
"  set backupdir=~/.tmp,.,/tmp

" let g:Tlist_Ctags_Cmd='/usr/bin/ctags'
" let g:Tlist_Inc_Winwidth=0
  let Tlist_Exit_OnlyWindow=1
	let Tlist_Use_Right_Window=1

" =============================================================================
" Status line
" =============================================================================
"       statusline:  customize contents of the windows' status line.
"       I prefer it this way:
"       Show the current buffer number and filename with info on
"       modification, read-only, and whether it is a help buffer
"       (show only when applied).
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)

"       Move the rest to the right side, eg a copyright text:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)%=(c)\ Michael\ Prokop

"       Show the value of the current character in ASCII and Hex:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=ASCII=%b\ HEX=%B

"       Show the current position with line+column+virtual_column:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=Pos=<%l\,%c%V>\ %P
"       Adding color through UserN groups:
" set   statusline=%1*[%02n]%*\ %2*%F%*\ %(\ %M%R%H)%)%=%3*Pos=<%l,%c%V>%*

"       My favourite statusline is:
"set statusline=%<[%n]\ %f\ %y\ %r\ %1*%m%*%w%=%(Column:\ %c%V%)%4(%)%-10(Line:\ %l%)\ %4(%)%p%%\ %P\ \ \ \ \ \ ASCII=%b\ HEX=%B\ \ \ \ \ %=(c)\ Michael\ Prokop

"       Another favourite:
"  set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=Pos=<%l\,%c%V>\ %P\=ASCII=%b\ HEX=%B)%=(c)\ Michael\ Prokop

"       User1: color for buffer number
" hi    User1 ctermfg=red   ctermbg=white
"       User2: color for filename
" hi    User2 ctermfg=green ctermbg=white
" hi    User2 ctermfg=green ctermbg=black
"       User3: color for position
" hi    User3 ctermfg=blue  ctermbg=white

"if $LANG == 'zh_CN.GBK'
"	set statusline=\[%l,%c%V\]%o\ %b\[0x%B\]\ %{ShowTab()}\ [%{BytePercent()}%%]%P\ %w%h%m%r[%{&ff}]%y%<%F%{\"[\".(&fenc==\"\"?&enc:&fenc).((exists(\"+bomb\")\ &&\ &bomb)?\",B\":\"\").\"]\ \"}%=\ %{strftime(\"%x\ 星期%a\ %R\",getftime(expand(\"%:p\")))}\ %n
"else
  " by WFG
	" set statusline=%f%(\ [%M%R%H%W]%)%=%(C%c%V%)%1(%)%-1(L%l/%L%)\ \ %p%%%{((&fenc==\"\")?\"\":\"\ \".&fenc)}
	" set statusline=\[%l,%c%V\]%o\ %b\[0x%B\]\ %{ShowTab()}\ [%{BytePercent()}%%]%P\ %w%h%m%r[%{&ff}]%y%<%F%{\"[\".(&fenc==\"\"?&enc:&fenc).((exists(\"+bomb\")\ &&\ &bomb)?\",B\":\"\").\"]\ \"}%=\ %{strftime(\"%x\ %R\",getftime(expand(\"%:p\")))}\ %n
"end

"set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\%{strftime(\"%d/%m/%y\ -\ %H:%M\")}
"set statusline=%F%m%r%h%w\ (%{&ff}){%Y}[%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\-\ %H:%M\")}
"set statusline=%<%F%h%m%r%h%w%y\ %{&ff}\ %{strftime(\"%d/%m/%Y-%H:%M\")}%=\col:%c%V\ ascii:%b\ pos:%o\ lin:%l\,%L\ %P
"set statusline=%{strftime(\"%c\",getftime(expand(\"%:p\")))}
"set statusline=%<%F%h%m%r%h%w%y\ %{&ff}\
"%{strftime(\"%c\",getftime(expand(\"%:p\")))}%=\ lin:%l\,%L\ col:%c%V\pos:%o\ ascii:%b\ %P


"       statusline:  customize contents of the windows' status line.
"       Can't see it? Check out "set laststatus"!
"       I prefer it this way:
"       Show the current buffer number and filename with info on
"       modification, read-only, and whether it is a help buffer
"       (show only when applied).
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)

"       Move the rest to the right side, eg a copyright text:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)%=(c)\ Michael\ Prokop

"       Show the value of the current character in ASCII and Hex:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=ASCII=%b\ HEX=%B

"       Show the current position with line+column+virtual_column:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=Pos=<%l\,%c%V>\ %P

"       Adding color through UserN groups:
" set   statusline=%1*[%02n]%*\ %2*%F%*\ %(\ %M%R%H)%)%=%3*Pos=<%l,%c%V>%*

"       One favourite:
" set   statusline=[%n]\ %f\ %(\ %M%R%H)%)\=Pos=<%l\,%c%V>\ %P\=ASCII=%b\ HEX=%B)%=(c)\ Michael\ Prokop

"       My favourite statusline is:
"    set statusline=%<[%n]\ %f\ %y\ %r\ %1*%m%*%w%=%(Column:\ %c%V%)%4(%)%-10(Line:\ %l%)\ %4(%)%p%%\ %P\ \ \ \ \ \ ASCII=%b\ HEX=%B\ \ \ \ \ %=(c)\ Michael\ Prokop


  set statusline=%<\ %1*%{GetBufferList(1)}%2*%{GetBufferList(2)}%1*%{GetBufferList(3)}%3*%*%w%=%(C%c%V%)%1(%)%-1(L%l/%L%)\ \ %p%%%{((&fenc==\"\")?\"\":\"\ \".&fenc)}

" function for bufferlist in statusline - written by Thomas Winkler
  function! GetBufferList(class)
    if(&buflisted == 0 || &buftype != '')
      if(a:class == 1)
        return &buftype
      endif
    endif

    let l:numBuffers = bufnr('$')
    let l:i = 0
    let l:c = 1

    if(3 == a:class)
      let l:bufferList = "  "
    else
      let l:bufferList = ''
    endif

    while(l:i <= l:numBuffers)
      let l:i = l:i + 1
      if bufnr("") == l:i
        let l:c = l:c + 1
      elseif bufnr("") == l:i-1
        let l:c = l:c + 1
      endif

      if(getbufvar(l:i, '&buflisted') == 1) " check if buffer is listed
        let l:bufName = bufname(l:i)

        if(strlen(l:bufName))
          let l:shortBufName = fnamemodify(l:bufName, ":t")
          let l:shortBufName = substitute(l:shortBufName, '[][()]', '', 'g')

          " check if buffer is readonly
          if (getbufvar(l:i, '&readonly'))
            let l:shortBufName = l:shortBufName . '|RO'
          endif

          if(l:c == a:class)
            if(getbufvar(l:i, '&modified') == 1) " check if buffer is modified
							let l:shortBufName = '+' . l:shortBufName
            "elseif(bufwinnr(l:i) != -1) " check if buffer is currently open in a window
            "  let l:shortBufName = '*' . l:shortBufName
            else
							let l:shortBufName = '|' . l:shortBufName
            endif
            if(2 != a:class)
              let l:shortBufName = l:shortBufName . ' '
            endif

            let l:bufferList = l:bufferList .  l:i . l:shortBufName
          endif

        endif
      endif
    endwhile

    return l:bufferList
  endfunction


function! MyTabLine()
	let s = ''
	for i in range(tabpagenr('$'))
		" select the highlighting
		if i + 1 == tabpagenr()
			let s .= '%#TabLineSel#'
		else
			let s .= '%#TabLine#'
		endif

		" set the tab page number (for mouse clicks)
		let s .= '%' . (i + 1) . 'T'

		" the label is made by MyTabLabel()
		let s .= ' %{MyTabLabel(' . (i + 1) . ')} '
	endfor

	" after the last tab fill with TabLineFill and reset tab page nr
	let s .= '%#TabLineFill#%T'

	" right-align the label to close the current tab page
	if tabpagenr('$') > 1
		let s .= '%=%#TabLine#%999X X'
	endif

	"echomsg 's:' . s
	return s
endfunction

function! MyTabLabel(n)
	let buflist = tabpagebuflist(a:n)
	let winnr = tabpagewinnr(a:n)
	let numtabs = tabpagenr('$')
	" account for space padding between tabs, and the "close" button
	let maxlen = ( &columns - ( numtabs * 2 ) - 4 ) / numtabs
	let tablabel = bufname(buflist[winnr - 1])
	" while strlen( tablabel ) < 4
		" let tablabel = tablabel . " "
	" endwhile
	let tablabel = fnamemodify( tablabel, ':t' )
	let tablabel = a:n . "|" . tablabel
	let tablabel = strpart( tablabel, 0, maxlen )
	return tablabel
endfunction

" set tabline=%!MyTabLine()

" set showtabline=1 " 2=always

" vim:sw=2:ts=2
