if filereadable("/etc/vim/vimrc")
  source /etc/vim/vimrc
endif

source ~/.vim/option.vimrc
source ~/.vim/function.vimrc
source ~/.vim/key.vimrc

source ~/.vim/encoding.vimrc
source ~/.vim/filetype.vimrc
source ~/.vim/abbr.vimrc

"source ~/.vim/gpgfiles.vimrc
"source ~/.vim/mlsetting.vimrc

if filereadable($VIMRUNTIME . "/macros/matchit.vim")
        source $VIMRUNTIME/macros/matchit.vim
endif

if filereadable($VIMRUNTIME . "/ftplugin/man.vim")
        source $VIMRUNTIME/ftplugin/man.vim
endif

" if &term == "screen"
" 	runtime macros/screenpaste.vim
" endif

if filereadable($HOME . "/.vim/personal.vimrc")
  source $HOME/.vim/personal.vimrc
endif
source ~/.vim/color.vimrc
