[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 1
[]

[Variables]
  [./u]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Executioner]
  # Preconditioned JFNK (default)
  type = Transient
  num_steps = 24
  dt = 1
[]



[Postprocessors]
  [./values]
    type = MyPostProc
    outData = stateVal
  [../]
[]

[Outputs]
  csv = true
[]

[Problem]
  solve = false
  kernel_coverage_check = false
[]
