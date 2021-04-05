# Import lpSolve package
library(lpSolve)

# Set coefficients of the objective function
f.obj <- c(600, 500)

# Set matrix corresponding to coefficients of constraints by rows
f.con <- matrix(c(5, 2,
                  1, 6,
                  3, 3), nrow = 3, byrow = TRUE)

# Set unequality/equality signs
f.dir <- c(">=", ">=", ">=")

# Set right hand side coefficients
f.rhs <- c(24, 18, 24)

# Final value (z)
lp("min", f.obj, f.con, f.dir, f.rhs)

# Variables final values
lp1 <- lp("min", f.obj, f.con, f.dir, f.rhs)
lp1$solution