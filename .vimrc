
set backspace=indent,eol,start  " make that backspace key work the way it should
set nocompatible                " vi compatible is LAME
set background=dark             " Use colours that work well on a dark background (Console is usually black)
set showmode                    " show the current mode
set clipboard=unnamed           " set clipboard to unnamed to access the system clipboard under windows
set ts=4
set shiftwidth=4
set softtabstop=4
set mouse=a
set smartindent
set number
inoremap { {<CR>;<CR>}<Esc>k$xA
inoremap ` <C-n>
inoremap <F2> `
inoremap <C-f> for(int i=0;i<n;++i)
inoremap <C-g> for(int i=n;i>0;--i)
