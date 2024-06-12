# pragma once

# include <vector>

# include <gtkmm.h>
# include <gtkmm/box.h>
# include <gtkmm/liststore.h>
# include <gtkmm/scrolledwindow.h>

# include "query_loader.hh"
# include "modes/thread_view/thread_view.hh"

namespace Astroid {

  class ThreadIndex : public Mode {
    public:
      ThreadIndex (MainWindow *, ustring, ustring = "");
      ~ThreadIndex ();

      QueryLoader queryloader;

      void open_thread (refptr<NotmuchThread>, bool new_window);

      Glib::RefPtr<ThreadIndexListStore> list_store;
      ThreadIndexListView * list_view;
      ThreadIndexScrolled * scroll;

      ustring name = ""; // used as title for default queries
      ustring query_string;

      virtual ustring get_label () override;
      void pre_close () override;

      void on_stats_ready ();

      bool on_index_action (ThreadView * tv, ThreadView::IndexAction);

      virtual void grab_modal () override;
      virtual void release_modal () override;

    private:
      void on_first_thread_ready ();
  };
}
