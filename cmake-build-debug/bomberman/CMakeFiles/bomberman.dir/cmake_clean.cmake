file(REMOVE_RECURSE
  "../../bomberman/bomberman.pdb"
  "../../bomberman/bomberman"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/bomberman.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
