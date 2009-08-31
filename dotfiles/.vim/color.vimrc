" vim color scheme previews
" http://www-2.cs.cmu.edu/~maverick/VimColorSchemeTest/index-C.html

hi Statement cterm=bold
hi Conditional cterm=bold
hi Repeat cterm=bold

highlight StatusLine   term=bold cterm=bold ctermfg=yellow ctermbg=blue   guifg=#d86020 guibg=#005c70 gui=bold
highlight StatusLineNC term=none cterm=none ctermfg=black  ctermbg=yellow guifg=#d86020 guibg=#005c70 gui=bold
highlight SpellErrors  term=bold cterm=underline ctermfg=red

highlight User1 term=inverse,bold  cterm=none         ctermfg=yellow ctermbg=blue guifg=#d86020 guibg=#005c70 gui=inverse
if &term == "rxvt-unicode" || (&term == "screen" && $COLORTERM =~ "rxvt")
  highlight User2 term=inverse,bold  cterm=bold ctermfg=red  ctermbg=yellow  guifg=#d86020 guibg=#005c70 gui=NONE
else
  highlight User2 term=inverse,bold  cterm=bold ctermfg=blue ctermbg=white   guifg=#d86020 guibg=#005c70 gui=NONE
endif
highlight link User3 User1
highlight User4 term=inverse,bold  cterm=inverse,bold ctermfg=Red    guifg=Red   gui=inverse
highlight User5 term=inverse,bold  cterm=inverse,bold ctermfg=Cyan   guifg=Cyan  gui=inverse

" highlight link TabLine User1
" highlight link TabLineFill User2
" highlight link TabLineSel User3
hi TabLineFill term=underline cterm=underline gui=underline
hi TabLineSel term=bold cterm=bold
