library(tidyverse)
library(imager)

frame <- load.image("C:/Users/HP/source/repos/Cat Game/Assests/Img/kitten right.png")

frame %>% as.data.frame() %>% 
  pivot_wider(names_from = cc, values_from = value) %>% 
  mutate(rgb = rgb(`1`,`2`,`3`)) %>% 
  filter(rgb != "#000000") %>% 
  select(x,y,rgb) %>% 
  group_by(x,y) %>% 
  mutate(r = col2rgb(rgb) %>% pluck(1) ,
         g = col2rgb(rgb) %>% pluck(2),
         b = col2rgb(rgb) %>% pluck(3)) %>% 
  mutate(code = glue::glue("gfx.PutPixel(x + {x}, {y} + y, {r}, {g}, {b})") %>% 
           str_replace(., "97, 97, 97", "accentR, accentG, accentB") %>% 
           str_replace(., "189, 189, 189", "mainR, mainG, mainB")) %>% 
  pull(code) %>% paste0(., collapse = ";\n") %>% 
  write_lines("C:/Users/HP/source/repos/Cat Game/Assests/kitten right.txt", sep = "\n")
