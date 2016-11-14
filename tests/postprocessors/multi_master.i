[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 1

[]

[Variables]
  [./u]
  [../]
[]

[Executioner]
  type = Steady

  # Preconditioned JFNK (default)
  solve_type = 'PJFNK'

  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]

[Problem]
  solve = false
  kernel_coverage_check = false
[]

[MultiApps]
  [./full_solve]
    type = FullSolveMultiApp
# not setting app_type to use the same app type of master, i.e. MooseTestApp
    execute_on = initial
    positions = '0 0 0
                 0 0 0
                 0 0 0
                 0 0 0
                 0 0 0
                 0 0 0
                 0 0 0
                 0 0 0'
    input_files = UserObjTest.i
  [../]
[]
