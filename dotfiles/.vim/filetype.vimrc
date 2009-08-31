
filetype on           " Enable fieltype detection
filetype indent on    " Enable filetype-specific indenting
filetype plugin on    " Enable filetype-specific plugins

if has("autocmd")

" Set some sensible defaults for editing C-files
augroup cprog
  " Remove all cprog autocommands
  au!

  " When starting to edit a file:
  "   For *.c and *.h files set formatting of comments and set C-indenting on.
  "   For other files switch it off.
  "   Don't change the order, it's important that the line with * comes first.
  " autocmd BufRead *       		set formatoptions=tcql nocindent comments&
  autocmd BufRead *.c,*.cpp,*.h set formatoptions=croql cindent comments=sr:/*,mb:*,el:*/,://
  autocmd BufRead *.c,*.cpp,*.h set noignorecase
augroup END

augroup scripts
  autocmd BufRead ruby,python,perl,*.rb,*.py,*.pl set noignorecase
  autocmd FileType python set omnifunc=pythoncomplete#Complete expandtab tabstop=8 
augroup END

augroup mail
  autocmd BufNewFile,BufRead mail,mutt* set expandtab tw=70 sts=8 ts=8 shiftwidth=8
  " autocmd BufNewFile,BufRead mail,mutt* set fileencoding=gbk
  autocmd BufNewFile,BufRead mail,mutt* setlocal spell spelllang=en_us
augroup END

augroup tex
  autocmd BufNewFile,BufRead *.tex setlocal spell spelllang=en_us
augroup END



endif " has ("autocmd")

