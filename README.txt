Description
===========

This is a drush command that provides a command line interface to the
drupal_lookup_path() API function. 

Why is this useful?
===================

For a project, I was given a list of URLs of path-aliased nodes that
needed to be copied from one Drupal site to another.  This drush 
command was the glue I needed to be able to do a bulk export of all
the nodes in the list using the 'drush node-export' command that
comes with the Node Export module.

Given a text file of URLs that looked like this:

    http://www.movesmart.org/guides/title/what-does-it-mean-close-home
    http://www.movesmart.org/guides/title/how-much-can-you-save-ditching-your-car
    http://www.movesmart.org/guides/title/accessibility-resources-landlords
    ...

I was able to use this one-liner to export the nodes to separate files:

    $ for line in `cut -f 4-6 -d "/" ~/guide_urls.txt`; do drush lp --source $line; done | cut -f 2 -d "/" | while read -r nid; do drush node-export-export $nid --file=/home/movesmart/guide_exports/$nid.node; done

Author
======

Geoffrey Hing <geoff@terrorware.com>
