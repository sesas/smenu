#ifndef GETOPT_H
#define GETOPT_H

/* None of these constants are referenced in the executable portion of */
/* the code ... their sole purpose is to initialize global variables.  */
/* """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""" */
#define BADCH (int)'@'
#define NEEDSEP (int)':'
#define MAYBESEP (int)'%'
#define ERRFD 2
#define EMSG ""
#define START "-"

/* Conditionally print out an error message and return (depends on the */
/* setting of 'opterr' and 'opterrfd').  Note that this version of     */
/* TELL() doesn't require the existence of stdio.h.                    */
/* """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""" */
#define TELL(S)                             \
  {                                         \
    if (eopterr && eopterrfd >= 0)          \
    {                                       \
      char option = (char)eoptopt;          \
      if (write(eopterrfd, (S), strlen(S))) \
        ;                                   \
      if (write(eopterrfd, &option, 1))     \
        ;                                   \
      if (write(eopterrfd, "\n", 1))        \
        ;                                   \
    }                                       \
  }

int
egetopt(int nargc, char ** nargv, char * ostr);

#endif
