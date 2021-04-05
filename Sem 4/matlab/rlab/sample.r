# Import lpSolve package
library(lpSolve)

# Set coefficients of the objective function
f.obj <- c(4, 5)

# Set matrix corresponding to coefficients of constraints by rows
f.con <- matrix(c(1, 2,
                  6, 6,
                  1, 0), nrow = 3, byrow = TRUE)

# Set unequality/equality signs
f.dir <- c("<=", "<=", "<=")

# Set right hand side coefficients
f.rhs <- c(10, 36, 4)

# Final value (z)
lp("max", f.obj, f.con, f.dir, f.rhs)

# Variables final values
lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
lp1$solution
